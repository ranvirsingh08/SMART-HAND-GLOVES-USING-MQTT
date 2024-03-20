// Function to Toggle GPIO
void toggle_gpio(const int );

// Function to Toggle LED
void toggle_led();

// Sensor Read Data
int get_value_from_sensor(const int GPIO_PIN);
int get_value_from_sensor_1();
int get_value_from_sensor_2();
int get_value_from_sensor_3();

void init_smart_gloves();

void get_values_for_motion();
void map_all_values();

void check_conditions_for_motions();

void OLED_init();
void OLED_commands_out();

void reconnect();
void setup_wifi();
void callback(char* topic, byte* payload, unsigned int length);