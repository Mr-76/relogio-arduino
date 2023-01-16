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

bool exit_test(){
  get_buttons_states();
  delay(700); //to not press too much
  return ((button3State == HIGH && button1State == HIGH));
}


void alarmMennu() {
  menu_selector = 0;
  long alarm_timing = 43800;  //hora atual em segundos
  //get_buttons_states();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ALARMEEEE");
  delay(1000);
  while (true) {
    get_buttons_states();
    lcd.clear();
    delay(1000);
    //calculando horas
    int hora = alarm_timing / 3600;
    int minutos = ((alarm_timing) % 3600)/60;
    int segundos = alarm_timing % 60;
    lcd.setCursor(0, 0);
    lcd.print(hora);
    lcd.setCursor(3,0);
    lcd.print(minutos);
    lcd.setCursor(6,0);
    lcd.print(segundos);
    delay(1000);
    if (exit_test()){
      break;
    }
  }
}