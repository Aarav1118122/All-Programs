#  unfinished


def balance(chemical_equation):
    reactants = chemical_equation.split(" -> ")[0]
    products = chemical_equation.split(" -> ")[1]
    reactants_compounds = reactants.split(" + ")
    products_compounds = products.split(" + ")

    reactants_elements = split_equation(reactants_compounds)
    products_elements = split_equation(products_compounds)

    return [reactants_elements, products_elements]


def split_equation(equation):
    elements = {}
    for compounds in equation:
        index = 1
        while index < (len(compounds) - 1):
            if compounds[index+1].isalpha():  # checking if symbol has two letters
                # index is the first letter of the symbol index + 1 is the second letter of symbol
                element_symbol = compounds[index] + compounds[index+1]
                # index in incremented by one because there is and extra letter added in the symbol
                index += 1
            else:
                element_symbol = compounds[index]

            if element_symbol in elements.keys():
                elements[element_symbol] += 1
            else:
                elements[element_symbol] = int(
                    compounds[0])*int(compounds[index + 1])
            index += 2

    return elements


print(balance("1Na1O1H1 + 1H1Cl1 -> 1Na1Cl1 + 1H2O1"))
