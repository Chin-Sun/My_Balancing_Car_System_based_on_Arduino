volatile bool mpuInterrupt = true;     
void dmpDataReady()
{
	mpuInterrupt = true;
}

void speed()
{
	if (flag == 0)
	{
		if (digitalRead(MPB))
			speedcount += 1;
		else
			speedcount -= 1;
	}
}

void flash()  
{
	float ft = analogRead(A1);
	fVol = ft * (5.0f / 1023.0f);

	if (fVol > 3.6)
		LED = HIGH;
	else
		LED = !LED;
	digitalWrite(13, LED);
}
