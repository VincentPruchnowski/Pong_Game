// Eviter les inclusions simultanées - Permet de n'inclure ce fichier que s'il n'a jamais été inclus
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
	// Quitter la fenêtre avec echap
	void InputHandler(Event event, RenderWindow& window);
private:
	Button button;
};

#endif
