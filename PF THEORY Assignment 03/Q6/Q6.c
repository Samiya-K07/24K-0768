#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Weather 
{
    float temperature;
    float rainfall;
    float windSpeed;
};

struct Crop 
{
    char cropType[50];
    char growthStage[50];
    float expectedYield;
    Weather *weather;
};

struct Equipment
{
    char equipmentType[50];
    char operationalStatus[50];
    float fuelLevel;
    char activitySchedule[100];
};

struct 
{
    float soilNutrients;
    float pHLevel;
    int pestActivity; 
} Sensor;
 
struct Field 
{
    char gpsCoordinates[100];
    float soilHealth;
    float moistureLevel;
    Crop *crops;         
    int numCrops;
    Equipment *equipment; 
    int numEquipment;
    Sensor *sensors;     
    int numSensors;
};

struct RegionalHub
{
    char regionName[50];
    Field *fields;       
    int numFields;
    float aggregateYield;
    char emergencyPlan[200];
} ;

void addField(RegionalHub *hub);
void addCrop(Field *field);
void addEquipment(Field *field);
void addSensor(Field *field);
void displayHubDetails(const RegionalHub *hub);

int main() {
    
   int numHubs;
   printf("Enter the number of regional hubs: ");
   scanf("%d", &numHubs);

   RegionalHub *hubs = (RegionalHub *)malloc(numHubs * sizeof(RegionalHub));
   if (!hubs) 
   {
        printf("Memory allocation failed for hubs1!\n");
        return 1;
    }

   for (int i = 0; i < numHubs; i++) 
   {
      printf("\nEnter details for Regional Hub %d:\n", i + 1);
      printf("Region Name: ");
      scanf(" %[^\n]", hubs[i].regionName);
      printf("Number of fields in this hub: ");
      scanf("%d", &hubs[i].numFields);

      hubs[i].fields = (Field *)malloc(hubs[i].numFields * sizeof(Field));
      if (!hubs[i].fields) 
      {
            printf("Memory allocation failed for fields in hub %s!!\n", hubs[i].regionName);
            return 1;
      }

      for (int j = 0; j < hubs[i].numFields; j++) 
      {
            addField(&hubs[i]);
        }
    }


    for (int i = 0; i < numHubs; i++) 
    {
        displayHubDetails(&hubs[i]);
    }

    for (int i = 0; i < numHubs; i++) 
    {
        for (int j = 0; j < hubs[i].numFields; j++) 
        {
            free(hubs[i].fields[j].crops);
            free(hubs[i].fields[j].equipment);
            free(hubs[i].fields[j].sensors);
        }
        free(hubs[i].fields);
    }
    
   free(hubs);

   return 0;
}

void addField(RegionalHub *hub) 
{
    static int fieldIndex = 0;
    Field *field = &hub->fields[fieldIndex++];
    printf("\nEnter GPS coordinates for Field %d: ", fieldIndex);
    scanf(" %[^\n]", field->gpsCoordinates);
    printf("Soil Health (out of 100): ");
    scanf("%f", &field->soilHealth);
    printf("Moisture Level (percentage): ");
    scanf("%f", &field->moistureLevel);

    printf("Enter number of crops in this field: ");
    scanf("%d", &field->numCrops);
    field->crops = (Crop *)malloc(field->numCrops * sizeof(Crop));
    
    for (int i = 0; i < field->numCrops; i++) 
    {
        addCrop(field);
    }

    printf("Enter number of equipment in this field: ");
    scanf("%d", &field->numEquipment);
    field->equipment = (Equipment *)malloc(field->numEquipment * sizeof(Equipment));
    
    for (int i = 0; i < field->numEquipment; i++) 
    {
        addEquipment(field);
    }

    printf("Enter number of sensors in this field: ");
    scanf("%d", &field->numSensors);
    field->sensors = (Sensor *)malloc(field->numSensors * sizeof(Sensor));
    
    for (int i = 0; i < field->numSensors; i++) 
    {
        addSensor(field);
    }
}

void addCrop(Field *field) 
{
    static int cropIndex = 0;
    Crop *crop = &field->crops[cropIndex++];
    printf("\nEnter Crop Type: ");
    scanf(" %[^\n]", crop->cropType);
    printf("Growth Stage: ");
    scanf(" %[^\n]", crop->growthStage);
    printf("Expected Yield (kg): ");
    scanf("%f", &crop->expectedYield);

    crop->weather = (Weather *)malloc(sizeof(Weather));
    printf("Weather Forecast:\n");
    printf("Temperature (°C): ");
    scanf("%f", &crop->weather->temperature);
    printf("Rainfall (mm): ");
    scanf("%f", &crop->weather->rainfall);
    printf("Wind Speed (km/h): ");
    scanf("%f", &crop->weather->windSpeed);
}

void addEquipment(Field *field) 
{
    static int equipmentIndex = 0;
    Equipment *equipment = &field->equipment[equipmentIndex++];
    printf("\nEnter Equipment Type: ");
    scanf(" %[^\n]", equipment->equipmentType);
    printf("Operational Status: ");
    scanf(" %[^\n]", equipment->operationalStatus);
    printf("Fuel Level (percentage): ");
    scanf("%f", &equipment->fuelLevel);
    printf("Activity Schedule: ");
    scanf(" %[^\n]", equipment->activitySchedule);
}

void addSensor(Field *field) 
{
    static int sensorIndex = 0;
    Sensor *sensor = &field->sensors[sensorIndex++];
    printf("\nSoil Nutrients Level: ");
    scanf("%f", &sensor->soilNutrients);
    printf("pH Level: ");
    scanf("%f", &sensor->pHLevel);
    printf("Pest Activity (0=No, 1=Yes): ");
    scanf("%d", &sensor->pestActivity);
}

void displayHubDetails(const RegionalHub *hub) 
{
    printf("\nRegional Hub: %s\n", hub->regionName);
    printf("Number of Fields: %d\n", hub->numFields);
    
    for (int i = 0; i < hub->numFields; i++) 
    {
        Field *field = &hub->fields[i];
        printf("\nField %d:\n", i + 1);
        printf("GPS Coordinates: %s\n", field->gpsCoordinates);
        printf("Soil Health: %.2f\n", field->soilHealth);
        printf("Moisture Level: %.2f%%\n", field->moistureLevel);

        for (int j = 0; j < field->numCrops; j++) 
        {
            Crop *crop = &field->crops[j];
            printf("Crop %d: Type=%s, Growth Stage=%s, Expected Yield=%.2fkg\n", j + 1, crop->cropType, crop->growthStage, crop->expectedYield);
            printf("Weather: Temperature=%.2f°C, Rainfall=%.2fmm, Wind Speed=%.2fkm/h\n", crop->weather->temperature, crop->weather->rainfall, crop->weather->windSpeed);
        }

        for (int j = 0; j < field->numEquipment; j++) 
        {
            Equipment *equipment = &field->equipment[j];
            printf("Equipment %d: Type=%s, Status=%s, Fuel Level=%.2f%%, Schedule=%s\n", j + 1, equipment->equipmentType, equipment->operationalStatus, equipment->fuelLevel, equipment->activitySchedule);
        }

        for (int j = 0; j < field->numSensors; j++) 
        {
            Sensor *sensor = &field->sensors[j];
            printf("Sensor %d: Nutrients=%.2f, pH=%.2f, Pest Activity=%s\n", j + 1, sensor->soilNutrients, sensor->pHLevel, sensor->pestActivity ? "Yes" : "No");
        }
    }
}
