static inline float distance(float x, float y){
  return x*x + y*y;
}

static inline float smoothstep(float t) {
    return t * t * (3.0f - 2.0f * t);
}
