import { Entity, genId, getEntityById, id } from './entity'

interface User extends Entity {
  name: string
  username: string
}

const users: User[] = [
  {
    id: genId(),
    name: 'Jack Smith',
    username: 'jackie',
  },
  {
    id: genId(),
    name: 'Homer Simpson',
    username: 'h.simp',
  },
]

const getUsers = () => users

const getUserById = (id: id): User | null => getEntityById(users, id)

export { User, getUsers, getUserById }
