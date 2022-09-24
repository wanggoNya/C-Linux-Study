#include <stdio.h>
#include <json-c/json.h>

int main() {

    char *buf = "{ \"aaa\" : \"sss\", \"bbb\" : \"111\", \"phoneNumber\": [ \"010-0000-0000\", \"010-1111-1111\", \"010-2222-2222\" ]  }";

    // read
    json_object *rootObj = json_tokener_parse(buf);

    // string
    json_object *obj = json_object_object_get(rootObj, "aaa");
    const char *str = json_object_get_string(obj);
    printf("%s\n", str);

    // int
    obj = json_object_object_get(rootObj, "bbb");
    int ival = json_object_get_int(obj);
    printf("%i\n", ival);

    // json-c/json.h 를 열어보면 더많은 타입을 확인할 수 있다.

    // json_object_object_foreach 를 이용해 key-value 방식의 배열도 처리할 수 있다.
    json_object *phoneNumber = json_object_object_get(rootObj, "phoneNumber");
    if (json_object_is_type(phoneNumber, json_type_array) == 1) {
        for (int i = 0; i < json_object_array_length(phoneNumber); i++) {
            obj = json_object_array_get_idx(phoneNumber, i);
            str = json_object_get_string(obj);
            printf("%s\n", str);
        }
    }

    // write
    json_object *newRootObj = json_object_new_object();
    json_object_object_add(newRootObj, "aaa", json_object_new_string("111"));
    printf("%s\n", json_object_get_string(newRootObj));

    return 0;
}
