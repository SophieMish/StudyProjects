#include <cstdio>

using namespace std;


struct NightLight {
    int price;
    int power;
    int voltage;
    int weight;
    bool have_touch_control;
    bool phoneApp_control;
    /*---------------------*/
    int extra_functions;
    union {
        bool voice_assistant;  //a nightlight a ability to talk to you
        bool clock; //a nightlight can be a alarm clock and a timer
        bool loudspeaker; //a night light not only a lamp but can play music
    };

};

void init(NightLight *nightlight,
          int price = 3490,
          int weight = 680,
          int power = 10,
          int voltage = 12,
          bool phoneApp_control = true,
          bool have_touch_control = true,
          int extra_functions = 0 // voice assistant is default
) {
    nightlight->price = price;
    nightlight->power = power;
    nightlight->voltage = voltage;
    nightlight->weight = weight;
    nightlight->phoneApp_control = phoneApp_control;
    nightlight->have_touch_control = have_touch_control;
    nightlight->extra_functions = extra_functions;
    switch (extra_functions) {
        case 0: {
            nightlight->voice_assistant = true;
            break;
        }
        case 1: {
            nightlight->clock = true;
            break;
        }
        case 2: {
            nightlight->loudspeaker = true;
            break;
        }
    }
}

void view(NightLight *nightlight) {
    printf("Price = %d ru\n", nightlight->price);
    printf("Weight = %d grams\n", nightlight->weight);
    printf("Power = %d W \n", nightlight->power);
    printf("Voltage = %d V \n", nightlight->voltage);
    if (nightlight->have_touch_control)
        printf("The nightlight type have touch control\n");
    else
        printf("The nightlight type can be control only with buttons\n");
    if (nightlight->phoneApp_control)
        printf("The nightlight type can be control from phone \n");
    else
        printf("The nightlight type can't be control from phone\n");
    printf("------------------------------------------------------------\n");
    //---------------------------------------------------------------------------------
    printf("This nightlight has some extra functions as:  \n");
    switch (nightlight->extra_functions) {
        case 0: {
            printf(" - you can control nightlight with voice assistant and talk to it\n");
            break;
        }
        case 1: {
            printf(" - this nightlight can be an alarm clock and a timer\n");
            break;
        }
        case 2: {
            printf(" - this nightlight can play music and podcasts\n");
            break;
        }
    }

printf("------------------------------------------------------------");
}

void switchOn(NightLight *nightlight) {
    printf("\nThe nightlight is TURN OFF, TURNING ON the light\n");
    printf("TURN ON\n------------------------------------------------------------");
}

void switchOff(NightLight *nightlight) {
    printf("\nThe nightlight is TURN ON, TURNING OFF the light");
    printf("\nTURN OFF\n------------------------------------------------------------");
}

void connectWithPhone(NightLight *nightlight) {
    if (nightlight->phoneApp_control) {
        printf("\nConnecting your phone with the lamp\n");
    } else return;
    printf("------------------------------------------------------------");
}

void switchModeOfLight(NightLight *nightlight) {
    printf("\nTurn on YELLOW COLOUR");
    printf("\nTurn on RED COLOUR");
    printf("\nTurn on BLUE COLOUR");
    printf("\nTurn on GREEN COLOUR");
    printf("\nTurn on WHITE COLOUR");
    printf("\n------------------------------------------------------------");
}

int main() {
    NightLight nightLight_smart, nightLight_kids, nightLight_noFunc;

    printf("\nTHE SMART NIGHTLIGHT\n");
    init(&nightLight_smart);
    view(&nightLight_smart);
    switchOn(&nightLight_smart);
    connectWithPhone(&nightLight_smart);
    switchModeOfLight(&nightLight_smart);
    switchOff(&nightLight_smart);
    printf("%c", '\n');

    printf("\nTHE NIGHTLIGHT FOR KIDS\n");
    init(&nightLight_kids, 2590, 15, 400, 10, false, false,1);
    view(&nightLight_kids);
    switchOn(&nightLight_kids);
    connectWithPhone(&nightLight_kids);
    switchModeOfLight(&nightLight_kids);
    switchOff(&nightLight_kids);
    printf("%c", '\n');

    printf("\nTHE NIGHTLIGHT WITH LOUDSPEAKER\n");
    init(&nightLight_noFunc, 1500, 450, 10, 12, false, false, 2);
    view(&nightLight_noFunc);
    switchOn(&nightLight_noFunc);
    connectWithPhone(&nightLight_noFunc);
    switchModeOfLight(&nightLight_noFunc);
    switchOff(&nightLight_noFunc);
    printf("%c", '\n');

    return 0;

}
