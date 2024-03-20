#define CORE 1
TaskHandle_t task_1,task_2,task_3,sound_task,client_task;
void get_test_value_from_sensor_1(void *data);
void get_test_value_from_sensor_2(void *data);
void get_test_value_from_sensor_3(void *data);
void client_task_callback(void *data);
void client_publish_data(void *data);