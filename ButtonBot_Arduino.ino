void carforward();
void carbackward();
void carturnleft();
void carturnright();
void carStop();
void startloop();

#define speed 100
#define t_speed 50

#define del 1000
#define t_del 200
#define stddel 200

int m1p1 = 27;
int m1p2 = 14;
int m2p1 = 33;
int m2p2 = 32;
int m1en = 26;
int m2en = 25;

int front = 15;
int back = 16;
int right = 17;
int left = 18;
int start = 19;

int list[20];
int count = 0;
int f = 1;
int b = 2;
int l = 3; 
int r = 4;
int s = 0;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);
  pinMode(m1en, OUTPUT);
  pinMode(m2en, OUTPUT);

  pinMode(front, INPUT);
  pinMode(back, INPUT);
  pinMode(right, INPUT);
  pinMode(left, INPUT);
  pinMode(start, INPUT);
  // Set outputs to LOW
  carStop();
}

void loop() {
  if (digitalRead(front) == HIGH) {
    list[count] = f;
    count++;
  }
  if (digitalRead(back) == HIGH) {
    list[count] = b;
    count++;
  }
  if (digitalRead(right) == HIGH) {
    list[count] = r;
    count++;
  }
  if (digitalRead(left) == HIGH) {
    list[count] = l;
    count++;
  }
  if (digitalRead(start) == HIGH) {
    list[count] = s;
    startloop();
  }
}

void carforward() {
  analogWrite(m1en, speed);
  analogWrite(m2en, speed);
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH);
  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);
  delay(del);
}
void carbackward() {
  analogWrite(m1en, speed);
  analogWrite(m2en, speed);
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, HIGH);
  delay(del);
}
void carturnleft() {
  analogWrite(m1en, t_speed);
  analogWrite(m2en, t_speed);
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);
  delay(t_del);
}
void carturnright() {
  analogWrite(m1en, t_speed);
  analogWrite(m2en, t_speed);
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH);
  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, HIGH);
  delay(t_del);
}
void carStop() {
  analogWrite(m1en, 0);
  analogWrite(m2en, 0);
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, LOW);
  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, LOW);
}

void startloop() {
  for(int i = 0; i <= 20; i++)
  {
    if (list[i] == s) {
      count = 0;
      break;
    }

    else if (list[i] == f) {
      carforward();
      carStop();
      delay(stddel);
    }
    else if (list[i] == b) {
      carbackward();
      carStop();
      delay(stddel);
    }
    else if (list[i] == l) {
      carturnleft();
      carforward();
      carStop();
      delay(stddel);
    }
    else if (list[i] == r) {
      carturnright();
      carforward();
      carStop();
      delay(stddel);
    }
  }
  list[0] = s;
  count = 0;
}