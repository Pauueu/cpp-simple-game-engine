// Klasa zawierająca wszystkie możliwe przycisku do użycia w Input Manager

enum class KeyCode {
    A, B, C, D,
    E, F, G, H,
    I, J, K, L,
    M, N, O, P,
    Q, R, S, T,
    U, V, W, X,
    Y, Z,
    
    UpArrow, DownArrow, LeftArrow, RightArrow,
    Space, Escape, LeftAlt, RightAlt,
    LeftCtrl, RightCtrl, Enter, LeftShift, 
    RightShift, Tab, CapsLock, Backspace,

    MouseLeft, MouseRight, MouseMiddle,

    Count // Służy do odczytania ilości możliwych opcji w klasie
};