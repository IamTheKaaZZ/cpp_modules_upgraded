#pragma once
# include <cstddef>
# include <iostream>
# include <string>

namespace SmartPointer {
class ShareCount {

	public:

		ShareCount() : m_count(0), m_weakLinks(0) {}
		ShareCount(unsigned const & start) : m_count(start), m_weakLinks(0) {}
		ShareCount(ShareCount const & src) = delete;
		ShareCount & operator=(ShareCount const & src) = default;
		~ShareCount() {}

		void	reset() { m_count = 0; }
		long int &	getCount() { return m_count; }
		long int &	getWeak() { return m_weakLinks; }
        bool    noRefs() { return (m_count + m_weakLinks < 2); }
		void	operator++() { m_count++; }     //++Sharecount
		void	operator++(int) { m_count++; }  //Sharecount++
		void	operator--() { m_count--; }
		void	operator--(int) { m_count--; }
		void	operator=(long int const & newVal) { m_count = newVal; }
		friend std::ostream &	operator<<(std::ostream & o, ShareCount const & r) {
			o << "ShareCount = " << r.m_count << '\n';
            o << "WeakCount = " << r.m_weakLinks << '\n';
			return o;
		}

	private:

		long int	m_count;
        long int    m_weakLinks;
};
}