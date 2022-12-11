#include <LiquidCrystal_I2C.h>
//future change each menu to an object....
//need to change the menu cases instead of if to switch and case.
LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

const int BUTTON1 = 8;
const int BUTTON2 = 7;
const int BUTTON3 = 6;

int button1State = 0;
int button2State = 0;
int button3State = 0;

int menu_selector = 0;

int menu_array[10];

char *array_menus[] = {
  "CLOCK", "RADIO FREQ", "INFRA RED", "nothing"
};

char *clock_menus[] = {
  "ALARM", "COUNTER", "CRONOMETER", "nothing"
};



//set up starts display and also the input buttons
void setup() {
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

//loop where the program starts
void loop() {
  get_buttons_states();      //receive buttons states
  decrease_increase_menu();  //testing if buttons are being pressed

  selection_menu();  //menu selection
  show_options();
}

//shows the menus options to display
void show_options() {
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print(array_menus[menu_selector]);
  lcd.setCursor(2, 1);  //x,y
  lcd.print(menu_selector);
  delay(1000);
}

//read all buttons states
void get_buttons_states() {
  button1State = digitalRead(BUTTON1);
  button2State = digitalRead(BUTTON2);
  button3State = digitalRead(BUTTON3);
}

//menu of selections,change to swich and case style..
void selection_menu() {
  get_buttons_states();
  if (button2State == HIGH) {
    if (menu_selector == 0) {
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print("menu_selecionado");
      delay(1000);
      clock_menu();
    } else if (menu_selector == 1) {
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print("menu_selecionado");
      delay(1000);
      radio_freq_menu();

    } else if (menu_selector == 2) {
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print("menu_selecionado");
      delay(1000);

      infra_red_menu();

    } else {
      ;
    }
  }
}

//change the menu control variable
void decrease_increase_menu() {
  if (button1State == HIGH) {
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print("buttom1 pressed");
    delay(1000);

    menu_selector--;

    limit_menu();


    lcd.setCursor(2, 1);
    lcd.print(menu_selector);
    delay(500);

    lcd.clear();


  } else if (button3State == HIGH) {
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print("buttom3 pressed");
    delay(1000);
    menu_selector++;
    limit_menu();


    lcd.setCursor(2, 1);
    lcd.print(menu_selector);
    delay(500);
    lcd.clear();

  } else {
    ;
  }
}

//limiting the menu values. no max than the array size no min than 0
void limit_menu() {
  if (menu_selector < 0) {
    menu_selector = 0;
  } else if (menu_selector >= 4) {
    menu_selector = 3;
  } else {
    ;
  }
}

//clock menu impl


//radio freq menu impl
void radio_freq_menu() {
  get_buttons_states();
  decrease_increase_menu();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("freq menu");
  while (button2State == LOW) {
    get_buttons_states();
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("exiting freq");
  delay(1000);
}

//infra red menu impl
void infra_red_menu() {
  menu_selector = 0;
  get_buttons_states();
  decrease_increase_menu();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("infra red menu");
  while (button2State == LOW) {
    get_buttons_states();

    decrease_increase_menu();
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("exiting infra");
  delay(1000);
}