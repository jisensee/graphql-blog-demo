import { Entity, genId, getEntityById, id } from './entity'

interface User extends Entity {
  isAuthor: boolean
  name: string
  username: string
  bio?: string
}

const users: User[] = [
  {
    id: genId(),
    isAuthor: true,
    name: 'Donald J. Trump',
    username: 'maga2020',
    bio:
      'I WON THIS ELECTION! DEMOCATRS ARE STEALING IT, SO SAD! TERRIBLE THINGS HAVE HAPPENED AT ELECTION NIGHT, THE RADICAL LEFT IS GOING TO DESTROY AMERICA. LAW AND ORDER!!!',
  },
  {
    id: genId(),
    isAuthor: false,
    name: 'Homer Simpson',
    username: 'duffBeerFtw',
    bio:
      'Ich hab 3 Kinder und kein Geld, warum kann ich nicht keine Kinder und 3 Geld haben?',
  },
  {
    id: genId(),
    isAuthor: true,
    name: 'Josph R. Biden',
    username: 'trumpSucksRofl',
    bio:
      'I may think that my wife is my sister but at least I know who won this election :D',
  },
  {
    id: genId(),
    isAuthor: false,
    name: 'Vladimir Putin',
    username: 'vladi420',
    bio:
      'I am very proud of you Donnie, keep up the good work. Just remember to get back to mother russia before the left takes over your country :P',
  },
]

const getUsers = () => users
const getAuthors = () => users.filter((u) => u.isAuthor)

const getUserById = (id: id): User | null => getEntityById(users, id)

export { User, getUsers, getAuthors, getUserById }
