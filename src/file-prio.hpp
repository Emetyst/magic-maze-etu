#ifndef FILE_PRIO_HPP
#define FILE_PRIO_HPP

#include "skip-list.hpp"

namespace MMaze {
	class FilePrio {
		public:
			FilePrio();
			~FilePrio();

			void push(Noeud* noeud, int cle);
			void change_priorite(Noeud* noeud);

		private:
			SkipList sl;
	};
}

#endif
