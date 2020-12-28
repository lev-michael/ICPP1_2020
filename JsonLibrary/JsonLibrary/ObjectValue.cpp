#include "pch.h"
#include "api.h"


ObjectValue::ObjectValue()
{
	this->object = new DynamicArray<KeyValuePair>();
}

ObjectValue::~ObjectValue()
{
	for (size_t i = 0; i < this->object->getSize(); i++)
	{
		delete this->object->getElementAt(i).getValue();
	}
	delete object;
}

void ObjectValue::append(const KeyValuePair& pair)
{
	object->append(pair);
}

std::string ObjectValue::serialize() const
{
	int size = object->getSize();
		std::string output = "{";
		for (size_t i = 0; i < size; i++)
		{
			KeyValuePair pair = object->getElementAt(i);

			output.append("\"" + pair.getKey());
			output.append("\":");
			output.append(pair.getValue()->serialize());
			if (i != size-1) {
				output.append(",");
			}
		}
		output.append("}");
		return output;
}

Value* ObjectValue::getValue(std::string key)
{
	for (size_t i = 0; i < this->object->getSize(); i++)
	{
		if (this->object->getElementAt(i).getKey() == key) {
			return this->object->getElementAt(i).getValue();
		}
	}
}
