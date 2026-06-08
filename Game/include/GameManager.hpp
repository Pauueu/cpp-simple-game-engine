#pragma once

class GameManager {
    public:
        static int startPlayerHP; // Początkowe życia gracza
        static int playerHP; // Aktualne życia gracza
        static int playerScore; // Wynik gracza

        static void resetValues(); // Metoda do resetowania wartości
};