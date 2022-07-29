#include "input.h"

// Constructeur
// Défini l'état des différents boutons = état non appuyé (false)
Input::Input()
{
	button.left = button.right = button.up = button.down
		= button.escape = false;
}

// Fonction qui accède à button (struc) et nous donne l'info private
Input::Button Input::GetButton(void) const
{
	// return de ce qui est private (pour y accéder)
	return button;
}

// Fonction de gestion des inputs
void Input::InputHandler(Event event, RenderWindow& window)
{
	// Fermer la fenêtre si on clique sur la croix
	if (event.type == Event::Closed)
	{
		// On ferme la fenêtre
		window.close();
	}

	// Gestion des inputs - Gestion des évenements du clavier
	if (event.type == Event::KeyPressed)
	{
		switch (event.key.code) // Code de la touche utilisée
		{
		case Keyboard::Escape:
			button.escape = true;
			break;
		case Keyboard::Left:
			button.left = true;
			break;
		case Keyboard::Right:
			button.right = true;
			break;
		case Keyboard::Down:
			button.down = true;
			break;
		case Keyboard::Up:
			button.up = true;
			break;
		default:
			break;
		}
	}

	// Touche relachée
	if (event.type == Event::KeyReleased)
	{
		switch (event.key.code) 
		{
		case Keyboard::Escape:
			button.escape = false;
			break;
		case Keyboard::Left:
			button.left = false;
			break;
		case Keyboard::Right:
			button.right = false;
			break;
		case Keyboard::Down:
			button.down = false;
			break;
		case Keyboard::Up:
			button.up = false;
			break;
		default:
			break;
		}
	}
}