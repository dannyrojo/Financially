import requests

def send_data_to_backend(agi):
    if not agi.isdigit():
        return "Invalid input. Please enter a numerical value."

    data = {"agi": agi}
    response = requests.post("http://localhost:5000/calculate", json=data)
    return response.text
