from utilities.calculator import calculate_double
from database.database import save_data

def process_data(data):
    user_id = data.get('user_id')
    agi = data.get('agi')
    try:
        agi = float(agi) 
    except ValueError:
        return {"error": "Invalid AGI value"}
    
    calculated_agi = calculate_double(agi)
    
    save_data(user_id, {"calculated_agi": calculated_agi})
    
    response = {
        "message": "Success",
        "calculated_agi": calculated_agi
    }
    
    return response
