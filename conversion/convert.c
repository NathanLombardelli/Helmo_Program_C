

float convertDistance(float distance,int isDistanceCM)
{

    if(isDistanceCM)
    {
        return 0.3937*distance;
    }
    else
    {
        return 2.54*distance;
    }


}

float convertTemperature(float temperature,int isTemperatureCelsius)
{

    if(isTemperatureCelsius)
    {

        return temperature*9/5+32;

    }
    else
    {

        return (temperature-32)*5/9;

    }

}
