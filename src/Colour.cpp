class Color {
public:
    // Member variables for color components
    unsigned char r; // Red component (0-255)
    unsigned char g; // Green component (0-255)
    unsigned char b; // Blue component (0-255)
    unsigned char a; // Alpha component (0-255, for transparency)

    // Constructor to initialize color
    Color(unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0, unsigned char alpha = 255)
        : r(red), g(green), b(blue), a(alpha) {}

    // Method to set color components
    void set(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255) {
        r = red;
        g = green;
        b = blue;
        a = alpha;
    }

    // You can add more methods here, like blending, converting to other color spaces, etc.
};