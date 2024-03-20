// Task Functions to get values
// Task 1
void get_test_value_from_sensor_1(void *data) {
  int next = 0;
  int prev = 3000;
  for (int i = 0; i < test_count; i++) {
    toggle_led();
    // Get value from Sensor min and maximum
    next = get_value_from_sensor_1();
    if (flag_for_min_max == 0) {
      if (next < prev) {
        prev = next;
      }
    } else {
      if (next > MIN_1) {
        prev = next;
      }
    }
    // DEBUG_LN(prev);
    vTaskDelay(50);
  }
  int *value = (int *)data;
  *value = prev;
  vTaskDelete(NULL);
}

// Task 2
void get_test_value_from_sensor_2(void *data) {
  int next = 0;
  int prev = 3000;
  for (int i = 0; i < test_count; i++) {
    toggle_led();

    // Get value from Sensor min and maximum
    next = get_value_from_sensor_2();
    if (flag_for_min_max == 0) {
      if (next < prev) {
        prev = next;
      }
    } else {
      if (next > MIN_2) {
        prev = next;
      }
    }
    // DEBUG_LN(prev);
    vTaskDelay(50);
  }
  int *value = (int *)data;
  *value = prev;
  vTaskDelete(NULL);
}

// Task 3
void get_test_value_from_sensor_3(void *data) {
  int next = 0;
  int prev = 3000;
  for (int i = 0; i < test_count; i++) {
    toggle_led();

    // Get value from Sensor min and maximum
    next = get_value_from_sensor_3();
    if (flag_for_min_max == 0) {
      if (next < prev) {
        prev = next;
      }
    } else {
      if (next > MIN_3) {
        prev = next;
      }
    }
    // DEBUG_LN(prev);
    vTaskDelay(50);
  }
  int *value = (int *)data;
  *value = prev;
  vTaskDelete(NULL);
}


void client_task_callback(void *data) {
  while (1) {
    if (!client.connected()) {
      reconnect();
    }
    client.loop();
    vTaskDelay(100);
  }
  vTaskDelete(NULL);
}
void client_publish_data(void *data)
{
  int i = *(int *)data;
  if (!client.connected()) {
    reconnect();
    vTaskDelay(pdMS_TO_TICKS(50));
  }
   String topic = "command";
    const char* message = messages[i].c_str();
    client.publish(topic.c_str(), message,true);
    String command_index = "c";
    String payload = String(i);
    client.publish(command_index.c_str(), payload.c_str(),true);
    vTaskDelay(pdMS_TO_TICKS(50));
    vTaskDelete(NULL);
}