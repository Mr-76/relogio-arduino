void clock_menu() {
  menu_selector = 0;
  get_buttons_states();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("clock menu");
  delay(500);
  lcd.clear();


  while (true) {
    get_buttons_states();
    lcd.setCursor(0, 0);
    lcd.print(clock_menus[menu_selector]);
    delay(700);
    lcd.clear();
    if (button2State == HIGH) {
      //aposs selecao nao esta funcionando!! obs
      //get_buttons_states();
      //lcd.setCursor(0, 0);
      //lcd.print("TEST");
      //delay(1000);
      //apos isso fica tudo sem nd no display:()
      if (menu_selector == 0) {
        //testar bloco de codigo prox vez
        //lcd.clear();
        //get_buttons_states();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("entrando");
        delay(1000);
        //get_buttons_states();
        alarmMennu();
      }
    }
    if (exit_test()) {
      break;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("exiting clock");
  delay(1000);
}

bool exit_test() {
  get_buttons_states();
  delay(700);  //to not press too much
  return ((button3State == HIGH && button1State == HIGH));
}


void alarmMennu() {
  menu_selector = 0;
  long alarm_timing = 43800;  //hora atual em segundos
  //get_buttons_states();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ALARMEEEE");
  int hora = alarm_timing / 3600;
  int minutos = ((alarm_timing) % 3600) / 60;
  int segundos = alarm_timing % 60;

  int time_array[3] = { hora, minutos, segundos };
  delay(1000);
  for (int i = 0; i < 3; i++) {
    get_buttons_states();
    while (true) {
      get_buttons_states();
      lcd.clear();
      delay(500);
      if (button1State == HIGH) {
        time_array[i]--;
      }
      if (button3State == HIGH) {
        time_array[i]++;
      }
      if (button2State == HIGH) {
        lcd.clear();
        lcd.print("NEXT");
        delay(700);
        break;
      }
      lcd.setCursor(0, 0);
      lcd.print(time_array[0]);
      lcd.setCursor(3, 0);
      lcd.print(time_array[1]);
      lcd.setCursor(6, 0);
      lcd.print(time_array[2]);
      delay(500);
    }
  }

  current_alarm = (time_array[0]) * 3600 + (time_array[1]) * 60 + (time_array[2]);
}

void check_clock() {
  //  if ( current_alarm != 0){
  //    if (rtc seconds == current_alarmseconds)
  //  }
}