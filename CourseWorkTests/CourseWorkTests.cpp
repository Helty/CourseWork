#define BOOST_TEST_MODULE "ChipherTest"
#include <boost/test/included/unit_test.hpp>
#include "../CourseWork/Permutation.cpp"
#include "../CourseWork/Vigenere.cpp"


BOOST_AUTO_TEST_SUITE(ChipherTest)

BOOST_AUTO_TEST_CASE(TestVigenere)
{
	Vigenere vigenere;
	vigenere.SetKey("andrew");

	BOOST_CHECK_EQUAL(vigenere.Decrypt(vigenere.Encrypt("")),"");
	BOOST_CHECK_EQUAL(vigenere.Decrypt(vigenere.Encrypt("andrew")), "andrew");
	BOOST_CHECK_EQUAL(vigenere.Decrypt(vigenere.Encrypt("tan9")), "tan9");
	BOOST_CHECK_EQUAL(vigenere.Decrypt(vigenere.Encrypt("this is true")), "this is true");

	vigenere.SetKey("tan");

	BOOST_CHECK_EQUAL(vigenere.Decrypt(vigenere.Encrypt("")), "");
	BOOST_CHECK_EQUAL(vigenere.Decrypt(vigenere.Encrypt("this is false")), "this is false");
	BOOST_CHECK_EQUAL(vigenere.Decrypt(vigenere.Encrypt("tan9")), "tan9");
	BOOST_CHECK_EQUAL(vigenere.Decrypt(vigenere.Encrypt("this is true")), "this is true");
}
BOOST_AUTO_TEST_CASE(TestPermutation)
{
	Permutation permutation;
	permutation.SetKey("312");

	BOOST_CHECK_EQUAL(permutation.Decrypt(permutation.Encrypt("")), "");
	BOOST_CHECK_EQUAL(permutation.Decrypt(permutation.Encrypt("and")), "and");
	BOOST_CHECK_EQUAL(permutation.Decrypt(permutation.Encrypt("rew")), "rew");
	BOOST_CHECK_EQUAL(permutation.Decrypt(permutation.Encrypt("dre")), "dre");

	permutation.SetKey("3412");

	BOOST_CHECK_EQUAL(permutation.Decrypt(permutation.Encrypt("")), "");
	BOOST_CHECK_EQUAL(permutation.Decrypt(permutation.Encrypt("work")), "work");

	permutation.SetKey("615324");

	BOOST_CHECK_EQUAL(permutation.Decrypt(permutation.Encrypt("")), "");
	BOOST_CHECK_EQUAL(permutation.Decrypt(permutation.Encrypt("andrew")), "andrew");
	BOOST_CHECK_EQUAL(permutation.Decrypt(permutation.Encrypt("workingThrid")), "workingThrid");
	BOOST_CHECK_EQUAL(permutation.Decrypt(permutation.Encrypt("this is true")), "this is true");
}

BOOST_AUTO_TEST_SUITE_END()