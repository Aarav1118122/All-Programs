import chemical_balancing    # The code to test
import unittest   # The test framework


class Balancing(unittest.TestCase):
    def test_balance(self):
        self.assertEqual(chemical_balancing.balance("Na1O1H1 + H1Cl1 -> Na1Cl1 + H2O1"),
                         {"N": 1, "O": 1, "H": 1, "H": 1, "C": 1})


if __name__ == '__main__':
    unittest.main()
