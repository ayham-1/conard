#define JS0_X = A0;
#define JS0_Y = A1;
#define JS1_X = A2;
#define JS1_Y = A3;

#define BTN1 = 7;
#define BTN2 = 8;

#define MAX_JS = 1023;
#define MIN_JS = 0;

const byte MSG_BYTE_BEGIN = 255;
const byte MSG_BYTE_END = 128;

struct MSG {
    short JS0_X;
    short JS0_Y;
    short JS1_X;
    short JS1_Y;
    byte BTN1;
    byte BTN2;
}

void setup() {
    pinMode(L_JS_X, INPUT);
    pinMode(L_JS_Y, INPUT);
    
    pinMode(R_JS_X, INPUT);
    pinMode(R_JS_Y, INPUT);

    pinMode(BTN1, INPUT);
    pinMode(BTN2, INPUT);

    Serial.begin(9600);
}

MSG msg;

void loop() {
    /* read joystick 0 */
    msg.JS0_X = analogRead(JS0_X);
    msg.JS0_Y = analogRead(JS0_Y);

    /* read joystick 1 */
    msg.JS1_X = analogRead(JS1_X);
    msg.JS1_Y = analogRead(JS1_Y);

    /* read button */
    msg.BTN1 = digitalRead(BTN1);
    msg.BTN2 = digitalRead(BTN2);
    
    Serial.write((byte*)&msg, sizeof(msg));
}
