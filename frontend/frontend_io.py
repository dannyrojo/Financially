import json
import requests

#VALIDATE
def create_dictionary(**kwargs):
    dictionary = {}
    for key, value in kwargs.items():
        dictionary[key] = value
    return dictionary

def check_if_number(dictionary):
    return all(isinstance(float(value), (float, int)) or value is None for value in dictionary.values())

def validate_and_wrap_data(**kwargs):
    dictionary = create_dictionary(**kwargs)
    if check_if_number(dictionary):
        return dictionary
    else:
        raise ValueError("Invalid or insufficient data provided")

#REQUEST
def send_data_to_backend(**input):
    try:
        data = validate_and_wrap_data(**input)
        response = requests.post("http://localhost:5000/calculate", json=data)
        response.raise_for_status()
        return response.text
    except requests.exceptions.RequestException as e:
        return f"Request Error: {str(e)}"
    except ValueError as e:
        return f"Validation Error: {str(e)}"
    except Exception as e:
        return f"Unexpected Error: {str(e)}"
