void motor(int v)
{
  if (flag == 7 || flag == 1 || flag == 2)
  {
    if(abs(Offset_Setpoint-osp)<dt)
      Offset_Setpoint += (double)(v + ds) / 1000.0;    
  }
  if (flag == 8 || flag == 3 || flag == 4)
  {
     if(abs(Offset_Setpoint-osp)<dt)
        Offset_Setpoint += (double)(v - ds) / 1000.0;   
  }
  
  if (flag == 5 && abs(v) < ds)
  {
    digitalWrite(AN1, HIGH);
    digitalWrite(AN2, LOW);
    digitalWrite(BN1, LOW);
    digitalWrite(BN2, HIGH);
    analogWrite(PWMA, ds-20);
    analogWrite(PWMB, ds-20);
  }
  else if (flag == 6 && abs(v) < ds)
  {
    digitalWrite(AN1, LOW);
    digitalWrite(AN2, HIGH);
    digitalWrite(BN1, HIGH);
    digitalWrite(BN2, LOW);
    analogWrite(PWMA, ds-20);
    analogWrite(PWMB, ds-20);
  }

  else if (v > 0)
  {
    digitalWrite(AN1, HIGH);
    digitalWrite(AN2, LOW);
    digitalWrite(BN1, HIGH);
    digitalWrite(BN2, LOW);
    if (flag == 4)
    {
      analogWrite(PWMA, v / 2);
      analogWrite(PWMB, v);
    }
    else if (flag == 3)
    {
      analogWrite(PWMA, v);
      analogWrite(PWMB, v / 2);
    }
    else
    {
      analogWrite(PWMA, v);
      analogWrite(PWMB, v);
    }
  }
  else if (v < 0)
  {
    v = -v;
    digitalWrite(AN1, LOW);
    digitalWrite(AN2, HIGH);
    digitalWrite(BN1, LOW);
    digitalWrite(BN2, HIGH);    
    if (flag == 2)
    {
      analogWrite(PWMA, v / 2);
      analogWrite(PWMB, v);
    }
    else if (flag == 1)
    {
      analogWrite(PWMA, v);
      analogWrite(PWMB, v / 2);
    }
    else
    {
      analogWrite(PWMA, v);
      analogWrite(PWMB, v);
    }
  }
  else
  {
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
  }
}

