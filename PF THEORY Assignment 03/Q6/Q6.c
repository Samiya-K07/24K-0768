#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct  
{
    float temperature;
    float rainfall;
    float wind_speed;
} Weather;

typedef struct  
{
    char crop_type[50];
    char growth_stage[50];
    float expected_yield;
    Weather *weather;
} Crop;

typedef struct 
{
    char equipment_type[50];
    char operational_status[50];
    float fuel_level;
    char activity_schedule[100];
} Equipment;

typedef struct 
{
    float soil_nutrients;
    float pH_level;
    int pest_activity; 
} Sensor;
 
typedef struct 
{
    char coordinates[100];
    float soil_health;
    float moisture_level;
    Crop *crops;         
    int num_of_crops;
    Equipment *equipment; 
    int num_of_equipment;
    Sensor *sensors;     
    int num_of_sensors;
} Field ;

typedef struct 
{
    char region_name[50];
    Field *fields;       
    int num_of_fields;
    float aggregate_yield;
    char emergency_plan[200];
} RegionalHub;

void AddField(RegionalHub *hub);
void AddCrop(Field *field);
void AddEquipment(Field *field);
void AddSensor(Field *field);
void DisplayHubDetails(const RegionalHub *hub);

int main() {
    
   int num_of_hubs;
   printf("Enter the number of regional hubs: ");
   scanf("%d", &num_of_hubs);

   RegionalHub *hubs = (RegionalHub *)malloc(num_of_hubs * sizeof(RegionalHub));
   
   if (!hubs) 
    {
        printf("Memory allocation failed!!\n");
        return 1;
    }

   for (int i = 0; i < num_of_hubs; i++) 
   {
      printf("\nEnter details for the Regional Hub %d:\n", i + 1);
      printf("Region Name: ");
      scanf(" %[^\n]", hubs[i].region_name);
      
      printf("Number of fields in this hub: ");
      scanf("%d", &hubs[i].num_of_fields);

      hubs[i].fields = (Field *)malloc(hubs[i].num_of_fields * sizeof(Field));
      
      if (!hubs[i].fields) 
      {
            printf("Memory allocation failed for fields in hub %s!!\n", hubs[i].region_name);
            return 1;
      }

      for (int j = 0; j < hubs[i].num_of_fields; j++) 
        {
            AddField(&hubs[i]);
        }
    }


    for (int i = 0; i < num_of_hubs; i++) 
    {
        DisplayHubDetails(&hubs[i]);
    }

    for (int i = 0; i < num_of_hubs; i++) 
    {
        for (int j = 0; j < hubs[i].num_of_fields; j++) 
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

void AddField(RegionalHub *hub) 
{
    static int field_index = 0;
    Field *field = &hub->fields[field_index++];
    
    printf("\nEnter GPS coordinates for Field %d: ", field_index);
    scanf(" %[^\n]", field->coordinates);
    
    printf("Soil Health (out of 100): ");
    scanf("%f", &field->soil_health);
    
    printf("Moisture Level (percentage): ");
    scanf("%f", &field->moisture_level);

    printf("Enter number of crops in this field: ");
    scanf("%d", &field->num_of_crops);
    field->crops = (Crop *)malloc(field->num_of_crops * sizeof(Crop));
    
    for (int i = 0; i < field->num_of_crops; i++) 
    {
        AddCrop(field);
    }

    printf("Enter number of equipment in this field: ");
    scanf("%d", &field->num_of_equipment);
    field->equipment = (Equipment *)malloc(field->num_of_equipment * sizeof(Equipment));
    
    for (int i = 0; i < field->num_of_equipment; i++) 
    {
        AddEquipment(field);
    }

    printf("Enter number of sensors in this field: ");
    scanf("%d", &field->num_of_sensors);
    field->sensors = (Sensor *)malloc(field->num_of_sensors * sizeof(Sensor));
    
    for (int i = 0; i < field->num_of_sensors; i++) 
    {
        AddSensor(field);
    }
}

void AddCrop(Field *field) 
{
    static int crop_index = 0;
    Crop *crop = &field->crops[crop_index++];
    
    printf("\nEnter Crop Type: ");
    scanf(" %[^\n]", crop->crop_type);
    
    printf("Growth Stage: ");
    scanf(" %[^\n]", crop->growth_stage);
    
    printf("Expected Yield (kg): ");
    scanf("%f", &crop->expected_yield);

    crop->weather = (Weather *)malloc(sizeof(Weather));
    
    printf("Weather Forecast:\n");
    printf("Temperature (°C): ");
    scanf("%f", &crop->weather->temperature);
    
    printf("Rainfall (mm): ");
    scanf("%f", &crop->weather->rainfall);
   
    printf("Wind Speed (km/h): ");
    scanf("%f", &crop->weather->wind_speed);
}

void AddEquipment(Field *field) 
{
    static int equipment_index = 0;
    Equipment *equipment = &field->equipment[equipment_index++];
    
    printf("\nEnter Equipment Type: ");
    scanf(" %[^\n]", equipment->equipment_type);
    
    
    printf("Operational Status: ");
    scanf(" %[^\n]", equipment->operational_status);
    
    printf("Fuel Level (percentage): ");
    scanf("%f", &equipment->fuel_level);
    
    printf("Activity Schedule: ");
    scanf(" %[^\n]", equipment->activity_schedule);
}

void AddSensor(Field *field) 
{
    static int sensor_index = 0;
    Sensor *sensor = &field->sensors[sensor_index++];
    
    printf("\nSoil Nutrients Level: ");
    scanf("%f", &sensor->soil_nutrients);
    
    printf("pH Level: ");
    scanf("%f", &sensor->pH_level);
    
    printf("Pest Activity (0=No, 1=Yes): ");
    scanf("%d", &sensor->pest_activity);
}

void DisplayHubDetails(const RegionalHub *hub) 
{
    printf("\nRegional Hub: %s\n", hub->region_name);
    printf("Number of Fields: %d\n", hub->num_of_fields);
    
    for (int i = 0; i < hub->num_of_fields; i++) 
    {
        Field *field = &hub->fields[i];
        
        printf("\nField %d:\n", i + 1);
        
        printf("GPS Coordinates: %s\n", field->coordinates);
        
        printf("Soil Health: %.2f\n", field->soil_health);
        
        printf("Moisture Level: %.2f%%\n", field->moisture_level);

        for (int j = 0; j < field->num_of_crops; j++) 
        {
            Crop *crop = &field->crops[j];
            
            printf("Crop %d:\nType=%s\nGrowth Stage=%s\nExpected Yield=%.2fkg\n\n", j + 1, crop->crop_type, crop->growth_stage, crop->expected_yield);
            printf("Weather:\nTemperature=%.2f°C\nRainfall=%.2fmm\nWind Speed=%.2fkm/h\n\n", crop->weather->temperature, crop->weather->rainfall, crop->weather->wind_speed);
        }

        for (int j = 0; j < field->num_of_equipment; j++) 
        {
            Equipment *equipment = &field->equipment[j];
            printf("Equipment %d:\nType=%s\nStatus=%s\nFuel Level=%.2f%%\nSchedule=%s\n\n", j + 1, equipment->equipment_type, equipment->operational_status, equipment->fuel_level, equipment->activity_schedule);
        }

        for (int j = 0; j < field->num_of_sensors; j++) 
        {
            Sensor *sensor = &field->sensors[j];
            printf("Sensor %d:\nNutrients=%.2f\npH=%.2f\nPest Activity=%s\n\n", j + 1, sensor->soil_nutrients, sensor->pH_level, sensor->pest_activity);
        }
    }
}
