void clock_menu(){
menu_selector = 0;
 get_buttons_states();
 decrease_increase_menu();
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("clock menu");
  while (button2State == LOW){
    get_buttons_states();
    decrease_increase_menu();
    lcd.setCursor(0, 0);
    lcd.print(clock_menus[menu_selector]);

  }
  lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("exiting clock");
 delay(1000);
}