#include "pch.h" 
#include "CppUnitTest.h"
#include "../Stack/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(StackTest)
    {
    public:

        TEST_METHOD(Stack_Empty_OnCreation_IsEmpty)
        {
            Stack s;
            Assert::IsTrue(s.empty(), L"Новый стек должен быть пустым.");
            Assert::AreEqual((size_t)0, s.size(), L"Размер пустого стека должен быть 0.");
        }

        TEST_METHOD(Stack_Push_WhenOneElementPushed_SizeIsOne)
        {
            Stack s;
            s.push(10);
            Assert::AreEqual((size_t)1, s.size(), L"После добавления одного элемента размер должен быть 1.");
            Assert::IsFalse(s.empty(), L"Стек не должен быть пустым после добавления элемента.");
        }

        TEST_METHOD(Stack_Push_WhenMultipleElementsPushed_TopIsLastElement)
        {
            Stack s;
            s.push(10);
            s.push(20);
            s.push(30);
            Assert::AreEqual(30, s.top(), L"top() должен возвращать последний добавленный элемент (30).");
        }

        TEST_METHOD(Stack_Pop_WhenCalledOnNonEmptyStack_ReturnsLastPushedElement)
        {
            Stack s;
            s.push(10);
            s.push(20);
            int popped = s.pop();
            Assert::AreEqual(20, popped, L"pop() должен вернуть последний добавленный элемент (20).");
            Assert::AreEqual((size_t)1, s.size(), L"После pop размер должен уменьшиться на 1.");
        }

        TEST_METHOD(Stack_Pop_WhenCalledOnEmptyStack_ThrowsOutOfRange)
        {
            Stack s;
            bool exceptionThrown = false;
            try {
                s.pop();
            }
            catch (const std::out_of_range&) {
                exceptionThrown = true;
            }
            Assert::IsTrue(exceptionThrown, L"pop() должен бросать исключение при вызове на пустом стеке.");
        }

        TEST_METHOD(Stack_Top_WhenCalledOnEmptyStack_ThrowsOutOfRange)
        {
            Stack s;
            bool exceptionThrown = false;
            try {
                int value = s.top(); // используем, чтобы подавить warning о неиспользуемой переменной
                (void)value;
            }
            catch (const std::out_of_range&) {
                exceptionThrown = true;
            }
            Assert::IsTrue(exceptionThrown, L"top() должен бросать исключение при вызове на пустом стеке.");
        }

        TEST_METHOD(Stack_Contains_WhenElementIsPresent_ReturnsTrue)
        {
            Stack s;
            s.push(10);
            s.push(20);
            Assert::IsTrue(s.contains(10), L"contains(10) должен вернуть true, если 10 присутствует в стеке.");
            Assert::IsTrue(s.contains(20), L"contains(20) должен вернуть true, если 20 присутствует в стеке.");
        }

        TEST_METHOD(Stack_Contains_WhenElementIsNotPresent_ReturnsFalse)
        {
            Stack s;
            s.push(10);
            Assert::IsFalse(s.contains(30), L"contains(30) должен вернуть false, если 30 отсутствует в стеке.");
        }

        TEST_METHOD(Stack_ToString_WhenMultipleElements_ReturnsCorrectFormat)
        {
            Stack s;
            s.push(5);
            s.push(10);
            Assert::AreEqual(std::string("[5, 10]"), s.toString(), L"toString() должен вернуть \"[5, 10]\".");
        }

    };
}
