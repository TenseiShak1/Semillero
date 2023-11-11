#include <ESP8266WiFi.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

// WiFi credentials
const char *ssid = "tu_ssid_wifi";
const char *password = "tu_clave_wifi";

// MySQL server details
IPAddress server_addr(192, 168, 1, 100);  // Dirección IP del servidor MySQL
const int port = 3306;                     // Puerto de MySQL
const char *user = "tu_usuario_mysql";
const char *password_mysql = "tu_clave_mysql";
const char *db_name = "tu_base_de_datos";

// Create an instance of the MySQL server
WiFiClient client;
MySQL_Connection conn((Client *)&client);

void setup() {
  Serial.begin(115200);

  // Conectar a WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  Serial.println("Conectado a WiFi");

  // Conectar a MySQL
  Serial.println("Conectando a MySQL...");
  if (conn.connect(server_addr, port, user, password_mysql)) {
    Serial.println("Conectado a MySQL");
  } else {
    Serial.println("Fallo al conectar a MySQL");
    return;
  }
}

void loop() {
  // Insertar datos en la tabla
  insertData();

  // Leer datos de la tabla
  readData();

  delay(5000);
}

void insertData() {
  Serial.println("Insertando datos en la tabla...");

  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);

  char INSERT_SQL[] = "INSERT INTO tu_tabla (campo1, campo2) VALUES ('valor1', 'valor2')";

  cur_mem->execute(INSERT_SQL);
  delete cur_mem;
}

void readData() {
  Serial.println("Leyendo datos de la tabla...");

  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);

  char SELECT_SQL[] = "SELECT * FROM tu_tabla";

  cur_mem->execute(SELECT_SQL);
  row_values *row = NULL;
  do {
    row = cur_mem->get_next_row();
    if (row != NULL) {
      for (int f = 0; f < cur_mem->get_num_fields(); f++) {
        Serial.print(row->values[f]);
        Serial.print(" ");
      }
      Serial.println();
    }
  } while (row != NULL);
  delete cur_mem;
}
