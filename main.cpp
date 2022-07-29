#include "main.h"

// Variables
// La fen�tre du jeu
RenderWindow window;
// Pour la gestion des inputs
Input input;
// Pour stocker la font
Font font;
// Pour stocker le texte
Text txt;

// Positions raquettes
float posRaquettesLeftX = 50;
float posRaquettesRightX = WIN_WIDTH - 70;
float posRaquettesLeftY = WIN_HEIGHT / 2;
float posRaquettesRightY = posRaquettesLeftY;
float raquettesSpeed = 0.25f;
int raquettesHeight = 150;
int raquettesWidth = 20;

// Infos balle
float ballSpeed = 0.075f;
Vector2f ballDir = Vector2f(1.5f, 2.0f);
float ballPosX = WIN_WIDTH / 2;
float ballPosY = WIN_HEIGHT / 2;

// Score
int scoreJ1 = 0;
int scoreJ2 = 0;

void RaquetteIA()
{
	posRaquettesRightY = ballPosY;
}

void UpdateBall() {
	// Position balle
	ballPosX += ballDir.x * ballSpeed;
	ballPosY += ballDir.y * ballSpeed;
	// Collisions de la balle
	// Raquette gauche ou droite touch�e ?
	if ((ballPosX < posRaquettesLeftX + raquettesWidth &&
		ballPosY > posRaquettesLeftX &&
		ballPosY+7 < posRaquettesLeftY + raquettesHeight &&
		ballPosY+7 > posRaquettesLeftY)
		||
		(ballPosX > posRaquettesRightX - raquettesWidth &&
			ballPosX < posRaquettesRightX &&
			ballPosY+7 < posRaquettesRightY + raquettesHeight &&
			ballPosY+7 > posRaquettesRightY)) {
		ballDir.x *= -1;
	}

	// Mur gauche
	if (ballPosX < 0) {
		scoreJ2++;
		ballPosX = WIN_WIDTH / 2;
		ballPosY = WIN_HEIGHT / 2;
		ballDir.x = fabs(ballDir.x); // Valeur absolue (positive)
		ballDir.y *= -1;
		SetText(txt, std::to_string(scoreJ1) + " | " + std::to_string(scoreJ2));
	}

	// Mur droit
	if (ballPosX > WIN_WIDTH) {
		scoreJ1++;
		ballPosX = WIN_WIDTH / 2;
		ballPosY = WIN_HEIGHT / 2;
		ballDir.x = -fabs(ballDir.x); //  Moins valeur absolue (n�gative)
		ballDir.y *= -1;
		SetText(txt, std::to_string(scoreJ1) + " | " + std::to_string(scoreJ2));
	}

	// Mur haut ou bas
	if (ballPosY > WIN_HEIGHT || ballPosY < 0) {
		ballDir.y *= -1;
	}
}


// Fonction main, point de d�part du programme
int main()
{
	// Cr�ation d'une fen�tre type RenderWindow
	window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Pong SFML C++", Style::Default);
	// Chargement de la font
	font.loadFromFile("res/Blankit.ttf");
	// On r�gle toutes les propi�t�s de celui-ci
	SetText(txt, to_string(scoreJ1) + " | " + to_string(scoreJ2));

	// Pr�paration des formes
	// Balle
	CircleShape circleShape(15);
	circleShape.setPosition(ballPosX, ballPosY);
	// Raquette gauche
	RectangleShape rectangleShape(Vector2f(raquettesWidth, raquettesHeight));
	rectangleShape.setPosition(posRaquettesLeftX, posRaquettesLeftY);
	// Raquette droite
	RectangleShape rectangleShape2(Vector2f(raquettesWidth, raquettesHeight));
	rectangleShape2.setPosition(posRaquettesLeftX, posRaquettesLeftY);

	// Boucle qui tourne tant que la fen�tre est ouverte
	while (window.isOpen())
	{
		Event event; // Varaible pour g�rer l'�venement
		// On boucle sur les �venements
		while (window.pollEvent(event))
		{
			// Gestion des inputs / events
			input.InputHandler(event, window);
		}
		// Gestion clavier / souris
		CheckBtn();
		RaquetteIA();
		// Position raquettes, balle
		rectangleShape.setPosition(posRaquettesLeftX, posRaquettesLeftY);
		rectangleShape2.setPosition(posRaquettesRightX, posRaquettesRightY);
		// Update ball
		UpdateBall();
		circleShape.setPosition(ballPosX, ballPosY);
		// Couleur de la fen�tre noir
		window.clear(Color::Black);
		// C'est ici que l'on dessine les �l�ments du jeu
		window.draw(txt);
		window.draw(circleShape);
		window.draw(rectangleShape);
		window.draw(rectangleShape2);
		// Dessiner � l'�cran tous les �l�ments
		window.display();
	}

	// Fin du programme
	return 0;
}

void SetText(Text& txt, String str)
{
	// On lui indique quelle police utiliser
	txt.setFont(font);
	// On indique la cha�ne de caract�res � afficher
	txt.setString(str);
	// On indique la taille de la police d'�criture
	txt.setCharacterSize(26);
	// On donne la couleur
	txt.setFillColor(Color::White);
	// Pos
	txt.setPosition((WIN_WIDTH / 2) - 40, 10);
}

void CheckBtn()
{
	// Raquette gauche
	if (input.GetButton().up == true)
	{
		posRaquettesLeftY -= raquettesSpeed;
		if (posRaquettesLeftY < 0)
			posRaquettesLeftY = 0;
	}
	if (input.GetButton().down == true)
	{
		posRaquettesLeftY += raquettesSpeed;
		if (posRaquettesLeftY + raquettesHeight > WIN_HEIGHT)
			posRaquettesLeftY = WIN_HEIGHT - raquettesHeight;
	}
	// Raquette droite
	if (input.GetButton().left == true)
	{
		posRaquettesRightY -= raquettesSpeed;
		if (posRaquettesRightY < 0)
			posRaquettesRightY = 0;
	}
	if (input.GetButton().right == true)
	{
		posRaquettesRightY += raquettesSpeed;
		if (posRaquettesRightY + raquettesHeight > WIN_HEIGHT)
			posRaquettesRightY = WIN_HEIGHT - raquettesHeight;
	}
	if (input.GetButton().escape == true)
	{
		window.close();
	}
}