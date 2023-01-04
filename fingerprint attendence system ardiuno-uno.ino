#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(5, 4, 3, 2, A4, A5);
struct student_detail{
  String name;
  String regno;
  int status;
};
student_detail student_registered[30];
void student_registered_database()
{
  student_registered[0]={"A0","18BLC0000",0};
  student_registered[1]={"A1","18BLC0001",0};
  student_registered[2]={"A2","18BLC0002",0};
  student_registered[3]={"A3","18BLC0003",0};
  student_registered[4]={"A4","18BLC0004",0};
  student_registered[5]={"A5","18BLC0005",0};
  student_registered[6]={"A6","18BLC0006",0};
  student_registered[7]={"A7","18BLC0007",0};
  student_registered[8]={"A8","18BLC0008",0};
  student_registered[9]={"A9","18BLC0009",0};
  student_registered[10]={"A10","18BLC0010",0};
  student_registered[11]={"A11","18BLC0011",0};
  student_registered[12]={"A12","18BLC0012",0};
  student_registered[13]={"A13","18BLC0013",0};
  student_registered[14]={"A14","18BLC0014",0};
  student_registered[15]={"A15","18BLC0015",0};
  student_registered[16]={"A16","18BLC0016",0};
  student_registered[17]={"A17","18BLC0017",0};
  student_registered[18]={"A18","18BLC0018",0};
  student_registered[19]={"A19","18BLC0019",0};
  student_registered[20]={"A20","18BLC0020",0};
  student_registered[21]={"A21","18BLC0021",0};
  student_registered[22]={"A22","18BLC0022",0};
  student_registered[23]={"A23","18BLC0023",0};
  student_registered[24]={"A24","18BLC0024",0};
  student_registered[25]={"A25","18BLC0025",0};
  student_registered[26]={"A26","18BLC0026",0};
  student_registered[27]={"A27","18BLC0027",0};
  student_registered[28]={"A28","18BLC0028",0};
  student_registered[29]={"A29","18BLC0029",0};
}
int find(String regno){
  int status=-1;
  for(int i=0;i<20;i++)
  {
    if(regno==student_registered[i].regno)
    {
      status=i;
    }
  }
  return status;
}
void setup(){
   Serial.begin(9600);
   lcd.begin(16, 2);
   lcd.setCursor(0,0);
  student_registered_database();
}
void loop()
{
  int status=-1;
  if(Serial.available()>0)
  {
    String reg_no=Serial.readString();
    status=find(reg_no);
    if(status>=0 && status<=29)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(student_registered[status].name);
      lcd.setCursor(0,1);
      lcd.print(student_registered[status].regno);
      delay(5000);
      student_registered[status].status=1;
    }
    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("not found");
      delay(5000);
    }
  }
  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Give your regno");
    delay(5000);
  }
}

