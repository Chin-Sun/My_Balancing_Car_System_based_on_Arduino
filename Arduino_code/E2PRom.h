void SetParamers()
{
	EEPROM.put(0, 160);
	EEPROM.put(4, osp);
	EEPROM.put(8, dl);
	EEPROM.put(12, sc);
	EEPROM.put(16, kp);
	EEPROM.put(20, ki);
	EEPROM.put(24, kd);
	EEPROM.put(28, sp);
	EEPROM.put(32, si);
	EEPROM.put(36, sd);
	EEPROM.put(40, ds);
	EEPROM.put(44, dt);
}

void GetParamers()
{
	unsigned char CF;
	EEPROM.get(0, CF);
	if (CF == 160)
	{
		EEPROM.get(4, osp);
		EEPROM.get(8, dl);
		EEPROM.get(12, sc);
		EEPROM.get(16, kp);
		EEPROM.get(20, ki);
		EEPROM.get(24, kd);
		EEPROM.get(28, sp);
		EEPROM.get(32, si);
		EEPROM.get(36, sd);
		EEPROM.get(40, ds);
		EEPROM.get(44, dt);
	}
	else
	{
		osp = 10;
		dl = 0;
		sc = 30000;
		kp = 11.0;    ki = 285.0;    kd = 0.37;
		sp = 1.3;    si = 67.0;    sd = 0.38;
		ds = 110;    dt = 3; 
		SetParamers();		
	}
}
