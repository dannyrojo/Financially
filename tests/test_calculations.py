import unittest
from utilities.calculator import calculate_monthly_payment

class TestFinancialCalculations(unittest.TestCase):

    def test_calculate_monthly_payment(self):
        self.assertAlmostEqual(
            calculate_monthly_payment(100000, 5, 30), 
            536.82, 
            places=2
        )

        self.assertAlmostEqual(
            calculate_monthly_payment(200000, 3.5, 15), 
            1429.77, 
            places=2
        )

if __name__ == '__main__':
    unittest.main()
