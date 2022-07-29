// Eviter les inclusions simultan�es - Permet de n'inclure ce fichier que s'il n'a jamais �t� inclus
#ifndef INPUT_H 
#define INPUT_H
#include <SFML/Graphics.hpp>

// Directement appeler les fonctions de l'ASFML
using namespace sf;

class Input
{
	struct Button { bool left, right, up, down, escape; };

public:
	// Prototype du constructeur
	Input();
	// Autres prototypes
	Button GetButton(void) const;
	// Quitter la fen�tre avec echap
	void InputHandler(Event event, RenderWindow& window);
private:
	Button button;
};

#endif
