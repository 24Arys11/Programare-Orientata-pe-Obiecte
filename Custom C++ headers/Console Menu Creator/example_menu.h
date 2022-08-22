#ifndef EXAMPLE_MENU_H_INCLUDED
#define EXAMPLE_MENU_H_INCLUDED

#include "console_menu_generator/console_menu_generator.h"

static class ExampleUI {

private:

	//

public:

	void launch() {

		int resolutionWidth;
		int resolutionHeight;
		bool playSound = true;

		// Menu objects
		Menu mainMenu(4);
		Menu newGameMenu(3);
		Menu loadGameMenu(2);
		Menu optionsMenu(4);
		Menu videoOptionsMenu(3);
		Menu extrasMenu(4);

		// Action Tokens
		const uint16_t newGameBeginer = 1;
		const uint16_t Intermediare = 2;
		const uint16_t Advanced = 3;
		const uint16_t Save1 = 4;
		const uint16_t Save2 = 5;
		const uint16_t lowRes = 6;
		const uint16_t midRes = 7;
		const uint16_t highRes = 8;
		const uint16_t soundToggle = 9;
		const uint16_t Controls = 10;
		const uint16_t artworksGallery = 11;
		const uint16_t changeNickname = 12;

		// Menus setup
		mainMenu.setHeader("This is the most awesome game ever created...");
		mainMenu.setOption(0, "New game");
		mainMenu.setSubmenu(0, &newGameMenu);
			newGameMenu.setOption(0, "Beginner");
			newGameMenu.setActionToken(0, newGameBeginer);
			newGameMenu.setOption(1, "Intermediare");
			newGameMenu.setActionToken(1, Intermediare);
			newGameMenu.setOption(2, "Advanced");
			newGameMenu.setActionToken(2, Advanced);
			newGameMenu.setExitOption("Back");
		mainMenu.setOption(1, "Load game");
		mainMenu.setSubmenu(1, &loadGameMenu);
			loadGameMenu.setOption(0, "Save 1");
			loadGameMenu.setActionToken(0, Save1);
			loadGameMenu.setOption(1, "Save 2");
			loadGameMenu.setActionToken(1, Save2);
			loadGameMenu.setExitOption("Back");
		mainMenu.setOption(2, "Options");
		mainMenu.setSubmenu(2, &optionsMenu);
			optionsMenu.setOption(0, "Video");
			optionsMenu.setSubmenu(0, &videoOptionsMenu);
				videoOptionsMenu.setHeader("WARNING ! If your graphics card is a graphics card...\n ...well, than I guess it's a graphics card !");
				videoOptionsMenu.setOption(0, "480x640");
				videoOptionsMenu.setActionToken(0, lowRes);
				videoOptionsMenu.setOption(1, "1080x720");
				videoOptionsMenu.setActionToken(1, midRes);
				videoOptionsMenu.setOption(2, "1980x1080");
				videoOptionsMenu.setActionToken(2, highRes);
				videoOptionsMenu.setExitOption("Back");
			optionsMenu.setOption(1, (playSound) ? "Sound: ON" : "Sound: OFF");
			optionsMenu.setActionToken(1, soundToggle);
			optionsMenu.setOption(2, "Controls");
			optionsMenu.setActionToken(2, Controls);
			optionsMenu.setOption(3, "Change username");
			optionsMenu.setActionToken(3, changeNickname);
			optionsMenu.setExitOption("Back");
		mainMenu.setOption(3, "Extras");
		mainMenu.setActionToken(3, artworksGallery);
		mainMenu.setExitOption("Quit");

		bool runMenu = true;
		while (runMenu) {

			// Action definitions
			switch (mainMenu.launch()) {
			case 0:
				runMenu = false;
				break;
			case newGameBeginer:
				std::cout << "Playing as Beginner..." << std::endl;
				break;
			case Intermediare:
				std::cout << "Playing as Intermediare..." << std::endl;
				break;
			case Advanced:
				std::cout << "Playing as Advanced..." << std::endl;
				break;
			case Save1:
				std::cout << "Playing as Save game 1..." << std::endl;
				break;
			case Save2:
				std::cout << "Playing as Save game 2..." << std::endl;
				break;
			case lowRes:
				std::cout << "Resolution set to 480x640 !" << std::endl;
				resolutionHeight = 480;
				resolutionWidth = 640;
				break;
			case midRes:
				std::cout << "Resolution set to 1080x720 !" << std::endl;
				resolutionHeight = 720;
				resolutionWidth = 1080;
				break;
			case highRes:
				std::cout << "Resolution set to 1920x1080 !" << std::endl;
				resolutionHeight = 1080;
				resolutionWidth = 1920;
				break;
			case soundToggle:
				playSound = !playSound;
				optionsMenu.setOption(1, (playSound) ? "Sound: ON" : "Sound: OFF");
				break;
			case Controls:
				std::cout << "You are changing the key mapping..." << std::endl;
				break;
			case artworksGallery:
				std::cout << "Ooo.. look.. How beautifull.. OMG.. ARTWORKS..." << std::endl;
				break;
			case changeNickname:
				std::cout << "New username: ";
				std::string newUser;

				// std::cin >> s; - stops at space characters, not just at new lines.
				// getline(std::cin, s); - only works reliably if istream buffer is cleared.
				// scanf(" "); - clears istream input buffer.
				scanf(" ");
				getline(std::cin, newUser);

				mainMenu.setInputTag(newUser);
				newGameMenu.setInputTag(newUser);
				loadGameMenu.setInputTag(newUser);
				optionsMenu.setInputTag(newUser);
				videoOptionsMenu.setInputTag(newUser);
				extrasMenu.setInputTag(newUser);

				break;
			}
		}
	}

}ExampleUI;

#endif /// EXAMPLE_MENU_H_INCLUDED