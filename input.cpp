#include "input.h"

// Constructeur
// D�fini l'�tat des diff�rents boutons = �tat non appuy� (false)
Input::Input()
{
	button.left = button.right = button.up = button.down
		= button.escape = false;
}

// Fonction qui acc�de � button (struc) et nous donne l'info private
Input::Button Input::GetButton(void) const
{
	// return de ce qui est private (pour y acc�der)
	return button;
}

// Fonction de gestion des inputs
void Input::InputHandler(Event event, RenderWindow& window)
{
	// Fermer la fen�tre si on clique sur la croix
	if (event.type == Event::Closed)
	{
		// On ferme la fen�tre
		window.close();
	}

	// Gestion des inputs - Gestion des �venements du clavier
	if (event.type == Event::KeyPressed)
	{
		switch (event.key.code) // Code de la touche utilis�e
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

	// Touche relach�e
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