// Implementation file for Game class

#include "game.h"

#include <iostream>
#include <limits>
#include <string>

using namespace std;

Game::Game() {
    // Constructor

    root_ = nullptr;
}

Game::~Game() {
    // Destructor
        // Delete decision tree

    DeleteNode(root_);
}

void Game::Play() {
    // Execute gameplay

    // Greeting
    cout << "Discover Your Medieval Personality!\n"
         << "Step back in time to the Middle Ages and find out which "
         << "character represents your unique personality.\n"
         << "Answer the questions in the story to unlock the secrets of your "
         << "medieval self!\n\n";

    // Get and store player name
    cout << "What is your name? > ";
    string player_name;
    getline(cin, player_name);
    player_.SetName(player_name);
    cout << "\n";

    // Create decision tree
    MakeGame();

    // Gameplay
    Node *curr = root_;  // Pointer to current node, starting at root
    cout << curr->GetText();  // Print root's text (story piece)

    // Do this while current node is not a leaf (end piece of story)
    do {
        // If the user chooses choice 1 (A)
        if (Ask() == 1) {
            // Remove choice 2's trait from player's tracker
            player_.RemoveTrait(curr->GetChoice2()->GetTrait());
            // Point curr to player's choice (choice 1)
            curr = curr->GetChoice1();
        }

        // If the user chooses choice 2 (B)
        else {
            // Remove choice 1's trait from player's tracker
            player_.RemoveTrait(curr->GetChoice1()->GetTrait());
            // Point curr to player's choice (choice 2)
            curr = curr->GetChoice2();
        }

        // Print node's text (story piece)
        cout << "\n" << curr->GetText();
    } while (!curr->IsLeaf());

    cout << "The End.\n\n";
    // Display player's final trait and its description
    cout << player_.GetName() << ", you are the " << GetTraitName();
}

void Game::MakeGame() {
    // Create decision tree

    // X (root)
    root_ = new Node(
        "You've been invited to a royal banquet.\n"
        "Which role do you choose for the evening?\n"
        "A. Protect the castle\n"
        "or\n"
        "B. Entertain the banquet\n\n",
        ' ');

    // X -> A
    root_->SetChoice(
        1,
        MakeNode(
            "During the banquet, a dragon threatens the queen's life.\n"
            "How do you handle it?\n"
            "A. Attempt to slay the dragon\n"
            "or\n"
            "B. Tame the dragon\n\n",
            'A'));

    // X -> A -> A
    root_->GetChoice1()->SetChoice(
        1,
        MakeNode(
            "You are very courageous.\n"
            "Which method do you choose?\n"
            "A. Wield your sword and cut off the dragon's head\n"
            "or\n"
            "B. Craft a special weapon to kill the dragon\n\n",
            'A'));

    // X -> A -> A -> A
    root_->GetChoice1()->GetChoice1()->SetChoice(
        1,
        MakeNode(
            "Your mortal sword is no match for the great dragon.\nThe dragon "
            "picks you up and crushes you as if discarding a wad of paper."
            "\n\n",
            'A'));

    // X-> A -> A -> B
    root_->GetChoice1()->GetChoice1()->SetChoice(
        2,
        MakeNode(
            "You create a magnificent poleaxe with obsidian from the "
            "dragon's lair.\nMade of the only material able to pierce the "
            "dragon's skin,\nyou drive the spear directly through its heart."
            "\n\n",
            'D'));

    // X -> A -> B
    root_->GetChoice1()->SetChoice(
        2,
        MakeNode(
            "A humane approach!\n"
            "How shall you do so?\n"
            "A. Craft a contraption to capture and tame the dragon\n"
            "or\n"
            "B. Use your magical powers to tame the dragon\n\n",
            'C'));

    // X -> A -> B -> A
    root_->GetChoice1()->GetChoice2()->SetChoice(
        1,
        MakeNode(
            "You are in the process of trapping the dragon when it gets "
            "spooked and lashes out.\nYou are incinerated by its fiery "
            "breath.\n\n",
            'D'));

    // X -> A -> B -> B
    root_->GetChoice1()->GetChoice2()->SetChoice(
        2,
        MakeNode(
            "Your powers have no effect on the mighty beast,\nbut the dragon "
            "recognizes your effort to prevent harm and retreats.\n\n",
            'C'));

    // X -> B
    root_->SetChoice(
        2,
        MakeNode(
            "While you're performing, the princess makes eye contact with "
            "you and starts to dance.\n"
            "How do you proceed?\n"
            "A. Continue to perform\n"
            "or\n"
            "B. Talk to the princess\n\n",
            'B'));

    // X -> B -> A
    root_->GetChoice2()->SetChoice(
        1,
        MakeNode(
            "Your performance is legendary and the court greatly appreciates "
            "your talent,\nbut in the middle of your performance somebody "
            "sabotages your instrument!\n"
            "What do you do?\n"
            "A. Use your voice and keep performing\n"
            "or\n"
            "B. Fix your instrument on the fly\n\n",
            'B'));

    // X -> B -> A -> A
    root_->GetChoice2()->GetChoice1()->SetChoice(
        1,
        MakeNode(
            "The princess smiles and enjoys the rest of your performance.\n"
            "The queen, impressed by your dedication, invites you to be the "
            "court bard.\n"
            "Your talent cements a legacy as a legendary figure in the "
            "kingdom.\n\n",
            'B'));

    // X -> B -> A -> B
    root_->GetChoice2()->GetChoice1()->SetChoice(
        2,
        MakeNode(
            "You quickly repair your instrument on the spot using your "
            "abilities,\ndemonstrating to the kingdom that you can face any "
            "unexpected challenges.\nEveryone is fascinated by both your "
            "performance and your quick repair show!\n"
            "People did not expect your expertise in both fields.\n\n",
            'D'));

    // X -> B -> B
    root_->GetChoice2()->SetChoice(
        2,
        MakeNode(
            "You and the princess fall in love. She invites you to her "
            "chambers,\nbut as you are sneaking through the halls of the "
            "castle you are spotted.\nThe royal guards take you to the "
            "dungeon, where you quickly decide you need to escape.\n"
            "How do you do it?\n"
            "A. Craft a tool with objects found in your cell, and use it to "
            "break out\n"
            "or\n"
            "B. Create a portal to escape to a different realm\n\n",
            'C'));

    // X -> B -> B -> A
    root_->GetChoice2()->GetChoice2()->SetChoice(
        1,
        MakeNode(
            "You have escaped and are running through the castle dungeon "
            "when you see a door to the outside.\nYou pry open the door and "
            "are running for your freedom when an archer from the tower "
            "shoots you.\nYou bleed to death.\n\n",
            'D'));

    // X -> B -> B -> B
    root_->GetChoice2()->GetChoice2()->SetChoice(
        2,
        MakeNode(
            "The princess comes back with the royal guards to an empty "
            "cell.\nShe calls her mage counselors who trace the portal"
            " back to you.\nThe princess joins you in the majestic realm "
            "where the two of you live happily ever after.\n\n",
            'C'));
}

Node *Game::MakeNode(string text, char trait) {
    // Create and return pointer to new dynamic Node variable

    Node *temp = new Node(text, trait);
    return temp;
}

void Game::DeleteNode(Node *node) {
    // Delete every node of the decision tree using recursion

    // Base case
    if (node == nullptr) {
    return;
    }

    // Set pointers to node's choices
    Node *temp1 = node->GetChoice1();
    Node *temp2 = node->GetChoice2();

    // Delete node
    delete node;

    // Recurse to both choices
    DeleteNode(temp1);
    DeleteNode(temp2);
}

int Game::Ask() {
    // Get the player's choice

    char choice;
    do {
        cout << "> ";

        // Input validation for upper or lower case 'A' or 'B'
        if (cin >> choice && cin.peek() == '\n'
                && (toupper(choice) == 'A' || toupper(choice) == 'B')) {
            break;
        } else {
            cout << "Please enter 'A' or 'B'\n";

            // Clear and ignore input stream in case more characters remain
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);

    // Return integer corresponding to player's choice
    if (toupper(choice) == 'A') {
    return 1;
    }
    return 2;
}

string Game::GetTraitName() const {
    // Return the trait name and description for the player's final trait

    string trait_name;
    switch (player_.GetFinalTrait()) {
    case 'A':
        trait_name = "Knight.\nAs a valiant knight you are known for your "
        "courage and dedication.\nWhether facing dragons or enemy invaders,\n"
        "you fearlessly wield your sword to defend the kingdom.\n"
        "Your heroic deeds in the battle have earned you the respect\n"
        "and admiration of both royalty and commonfolk alike!\n\n";
        break;

    case 'B':
        trait_name = "Bard.\nAs a charismatic bard, your performances captivate "
        "audiences\nand leave a beautiful impression on all who witness your "
        "talent.\nYour musical and entertaining presence makes you the kingdom's "
        "preferred artist.\nYou bring joy and light to the community, making you "
        "a beloved figure in your social circles.\n\n";
        break;

    case 'C':
        trait_name = "Mage.\nYou are a master of the arcane arts, and you "
        "possess mystical powers\nthat set you apart from the ordinary citizens "
        "of the medieval world.\nWhether it is taming dragons or casting spells "
        "to aid the kingdom,\nyour magical abilities make you a powerful "
        "person.\nPeople look up to you for your wisdom and innovative thinking."
        "\n\n";
        break;

    case 'D':
        trait_name = "Craftsman.\nYou are the master of the crafts,\nand your "
        "ingenuity and craftsmanship are far beyond your era.\nYou craft weapons "
        "to aid knights, contraptions to tame dragons,\nand tools to help "
        "everyday life situations.\nYour creations are always required in the "
        "kingdom and you are indispensable to the community.\nYour meaningful "
        "contributions make you an indispensable member of your social circle."
        "\n\n";
        break;
    }

    return trait_name;
}