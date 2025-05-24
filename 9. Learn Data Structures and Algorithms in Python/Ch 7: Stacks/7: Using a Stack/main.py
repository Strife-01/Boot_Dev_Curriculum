from stack import Stack


def is_balanced(input_str):
    st = Stack()
    for bracket in input_str:
        if bracket == '(':
            st.push('(')
        elif bracket == ')':
            ret = st.pop()
            if ret == None:
                return False
    if st.size() != 0:
        return False
    return True

