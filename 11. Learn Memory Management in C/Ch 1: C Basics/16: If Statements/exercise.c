#include "exercise.h"

char *get_temperature_status(int temp) {
  if (temp > 90) {
    return "too hot";
  } else if (temp < 70) {
    return "too cold";
  }
  return "just right";
}
