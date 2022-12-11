void clock_menu() {
  menu_selector = 0;
  get_buttons_states();
  decrease_increase_menu();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("clock menu");
  delay(500);
  lcd.clear();
  

  while (true) {
    get_buttons_states();
    decrease_increase_menu();
    lcd.setCursor(0, 0);
    lcd.print(clock_menus[menu_selector]);
    if (button2State == HIGH) {
      //aposs selecao nao esta funcionando!! obs
         
      get_buttons_states();
      decrease_increase_menu();
      lcd.setCursor(0, 0);
      lcd.print("TEST");
      delay(1000);
      //apos isso fica tudo sem nd no display:()
      if (menu_selector == 0) {


	 //testar bloco de codigo prox vez
         lcd.clear();
         get_buttons_states();
         decrease_increase_menu();
         lcd.setCursor(0, 0);
         lcd.print("TEST");
         delay(1000);


        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("entrando");
        get_buttons_states();
        alarmMennu();
      }
    }
    if (button3State == HIGH && button1State == HIGH){
      break;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("exiting clock");
  delay(1000);
}




void alarmMennu() {
  menu_selector = 0;
  int alarm_timing = 1000;  //hora atual em segundos
  get_buttons_states();
  decrease_increase_menu();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ALARMEEEE");
  while (true) {
    lcd.clear();
    delay(1000);
    //calculando horas
    alarm_timing = 1000;  //hora atual em segundos
    int hora = alarm_timing / 360;
    int minutos = (alarm_timing - hora) * 360;
    int segundos = (hora + minutos) - alarm_timing;

    lcd.setCursor(0, 0);
    lcd.print("STUFF");
    //lcd.setCursor(3, 0);
    //lcd.print(minutos);
    //lcd.setCursor(5, 0);
    //lcd.print(segundos);

    decrease_increase_menu();
  }
}
