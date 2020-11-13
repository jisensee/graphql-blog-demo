import { Entity, genId, getEntityById, id } from './entity'

interface User extends Entity {
  isAuthor: boolean
  name: string
  username: string
}

const users: User[] = [
  {
    id: genId(),
    isAuthor: true,
    name: 'Jack Smith',
    username: 'jackie',
  },
  {
    id: genId(),
    isAuthor: false,
    name: 'Homer Simpson',
    username: 'h.simp',
  },
]

const getUsers = () => users
const getAuthors = () => users.filter((u) => u.isAuthor)

const getUserById = (id: id): User | null => getEntityById(users, id)

export { User, getUsers, getAuthors, getUserById }
