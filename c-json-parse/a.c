#include <json-c/json.h>
#include <stdio.h>

void json_parse(json_object * jobj) {
  enum json_type type;
  json_object_object_foreach(jobj, key, val) {
    printf("type: ",type);
    type = json_object_get_type(val);
    switch (type) {
      case json_type_null: printf("json_type_nulln");
                           break;
      case json_type_boolean: printf("json_type_booleann");
                           printf("          value: %dn", json_object_get_boolean(val));
                           break;
      case json_type_double: printf("json_type_doublen");
                          printf("          value: %lfn", json_object_get_double(val));
                           break;
      case json_type_int: printf("json_type_intn");
                          printf("          value: %dn", json_object_get_int(val));
                           break;
      case json_type_object: printf("json_type_objectn");
                           jobj = json_object_object_get(jobj, key);
                           json_parse(jobj);
                           break;
      case json_type_string: printf("json_type_stringn");
                           printf("          value: %sn", json_object_get_string(val));
                           break;
    }
  }
}
int main() {
  char * string = "{"sitename" : "joys of programming",
                     "author-details": { "admin": false, "name" : "Joys of Programming", "Number of Posts" : 10 } 
                     }";
  json_object * jobj = json_tokener_parse(string);
  json_parse(jobj);
}
