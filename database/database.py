database = {}

def save_data(user_id, data):
    database[user_id] = data

def get_data(user_id):
    return database.get(user_id)
