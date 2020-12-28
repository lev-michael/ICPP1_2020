#include "api.h"
#include <iostream>

using namespace std;

void main() {
	ObjectValue* ov = new ObjectValue{};
	ov->append(KeyValuePair{ "bool", new BoolValue{true} });
	ov->append(KeyValuePair{ "null", new NullValue{} });
	ov->append(KeyValuePair{ "string", new StringValue{"hello world \\ \" experiment"} });
	ov->append(KeyValuePair{ "number", new NumberValue{3.141592} });

	ArrayValue* av = new ArrayValue{};
	av->append(new NumberValue{ 0 });
	av->append(new NumberValue{ 1 });
	av->append(new StringValue{ "two" });
	av->append(new NumberValue{ 3 });
	ObjectValue* four = new ObjectValue{};
	four->append(KeyValuePair{ "four", new NumberValue{4} });
	av->append(four);
	av->append(new NumberValue{ 5 });

	ov->append(KeyValuePair{ "array", av });
	string json = ov->serialize();
	cout << json;
	Value* value = JSON::deserialize(json);
}