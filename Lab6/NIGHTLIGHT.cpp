#include <cstdio>

using namespace std;


struct NightLight {
    int price;
    int power;
    int voltage;
    int weight;
    bool have_touch_control;
    bool phoneApp_control;
};

void init(NightLight *nightlight,
          int price = 3490,
          int weight = 680,
          int power = 10,
          int voltage = 12,
          bool phoneApp_control = true,
          bool have_touch_control = true
    ) {
    nightlight->price = price;
    nightlight->power = power;
    nightlight->voltage = voltage;
    nightlight->weight = weight;
    nightlight->phoneApp_control=phoneApp_control;
    nightlight->have_touch_control=have_touch_control;
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
    printf("------------------------------------------------------------");
}

void switchOn(NightLight* nightlight) {
        printf("\nThe nightlight is TURN OFF, TURNING ON the light\n");
        printf("TURN ON\n------------------------------------------------------------");

}

void switchOff(NightLight *nightlight) {
        printf("\nThe nightlight is TURN ON, TURNING OFF the light");
        printf("\nTURN OFF\n------------------------------------------------------------");
}

int connectWithPhone(NightLight *nightlight) {
        if (nightlight->phoneApp_control) {
                printf("\nConnecting your phone with the lamp\n");
        } else return 0;
        printf("------------------------------------------------------------");
    return 0;
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
    NightLight nightLight_smart, nightLight_kids;

    printf("\nTHE SMART NIGHTLIGHT\n");
    init(&nightLight_smart);
    view(&nightLight_smart);
    switchOn(&nightLight_smart);
    connectWithPhone(&nightLight_smart);
    switchModeOfLight(&nightLight_smart);
    switchOff(&nightLight_smart);
    printf("%c", '\n');

    printf("\nTHE NIGHTLIGHT FOR KIDS\n");
    init(&nightLight_kids, 2590, 15, 400, 10, false, false);
    view(&nightLight_kids);
    switchOn(&nightLight_kids);
    connectWithPhone(&nightLight_kids);
    switchModeOfLight(&nightLight_kids);
    switchOff(&nightLight_kids);
    printf("%c", '\n');

    return 0;
}
