from flask import Flask, request, jsonify
from .backend_io import process_data

app = Flask(__name__)

@app.route('/calculate', methods=['POST'])
def calculate_agi():
    data = request.get_json()
    response = process_data(data)
    return jsonify(response)

if __name__ == '__main__':
    app.run()
