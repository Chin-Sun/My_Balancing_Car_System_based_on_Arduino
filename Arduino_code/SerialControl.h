void SendData()
{
	num++;
	if (num < 20)
		return;

	num = 0;
	if (iSendType==1)
	{
		Serial.print("*22:");	Serial.print(Offset_Setpoint);
		Serial.print("|");		    Serial.print(dl);		
		Serial.print("|");			Serial.print(kp);
		Serial.print("|");			Serial.print(ki);
		Serial.print("|");			Serial.print(kd);
		Serial.print("|");			Serial.print(sp);
		Serial.print("|");			Serial.print(si);
		Serial.print("|");			Serial.print(sd);
		Serial.print("|");			Serial.print(ds);
		Serial.print("|");			Serial.print(dt);
		Serial.println("#");
	}
	else if (iSendType == 2)
	{
		Serial.print("*11:");		Serial.print(angle);
		Serial.print("|");		Serial.print(Output);		
		Serial.print("|");		Serial.print(fVol);
		Serial.println("#");
	}
}

void SerialControl()
{
	if (readCompleted)
	{		
		if (oString != nString)
		{
			oString = nString;
			iPos = oString.indexOf(':');
			strSS[0] = oString.substring(0, iPos);
			strSS[1] = oString.substring(iPos + 1, oString.length());
			
			if (strSS[0] == "GetParam")
				iSendType = 1;
			else if (strSS[0] == "EnableSend")
				iSendType = 2;
			else if (strSS[0] == "DisableSend")
				iSendType = 0;
			else if (strSS[0] == "SaveParam")
				SetParamers();
			else if (strSS[0] == "Reload")
			{
				GetParamers();
				speedcount = sc;
				Offset_Setpoint = osp;
				iSendType = 1;
			}
			else if (strSS[0] == "ResetParam")
			{
				EEPROM.put(0, 100);
				GetParamers();
				speedcount = sc;
				Offset_Setpoint = osp;
				iSendType = 1;
			}
			else if (strSS[0] == "Setpoint")
				osp = Offset_Setpoint = strSS[1].toDouble();
			else if (strSS[0] == "DL")
				dl = strSS[1].toInt();		
			else if (strSS[0] == "KP")
				kp = strSS[1].toDouble();				
			else if (strSS[0] == "KI")
				ki = strSS[1].toDouble();
			else if (strSS[0] == "KD")			
				kd = strSS[1].toDouble();				
			else if (strSS[0] == "SP")			
				sp = strSS[1].toDouble();			
			else if (strSS[0] == "SI")			
				si = strSS[1].toDouble();				
			else if (strSS[0] == "SD")			
				sd = strSS[1].toDouble();				
			else if (strSS[0] == "DS")			
				ds = strSS[1].toDouble();			
			else if (strSS[0] == "DT")			
				dt = strSS[1].toDouble();	        
			else if (strSS[0] == "Go")
      {
				//Offset_Setpoint += ds;
        flag = 7;
      }
			else if (strSS[0] == "Back")		
      {	
				//Offset_Setpoint -= ds;
        flag = 8;
      }
			else if (strSS[0] == "Center")
			{
				Offset_Setpoint = osp;
				flag = 0;
			}
			else if (strSS[0] == "LeftGo")
			{
				//Offset_Setpoint += dt;
				flag = 1;
			}
			else if (strSS[0] == "RightGo")
			{
				//Offset_Setpoint += dt;
				flag = 2;
			}
			else if (strSS[0] == "LeftBack")
			{
				//Offset_Setpoint -= dt;
				flag = 3;
			}
			else if (strSS[0] == "RightBack")
			{
				//Offset_Setpoint -= dt;
				flag = 4;
			}
			else if (strSS[0] == "Left")
			{
				flag = 5;
			}
			else if (strSS[0] == "Right")
			{
				flag = 6;
			}
		}
		nString = "";
		readCompleted = false;
	}
}

void serialEvent()
{
	while (Serial.available() && !readCompleted)
	{
		char inChar = (char)Serial.read();
		if (inChar != '\n')
			nString += inChar;
		else
			readCompleted = true;
	}
}



