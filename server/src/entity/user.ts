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
      'I WON THIS ELECTION! DEMOCRATS ARE STEALING IT, SO SAD! TERRIBLE THINGS HAVE HAPPENED AT ELECTION NIGHT, THE RADICAL LEFT IS GOING TO DESTROY AMERICA. LAW AND ORDER!!!',
  },
  {
    id: genId(),
    isAuthor: false,
    name: 'Barack Obama',
    username: 'BlackLifesMatter',
    bio: 'The last 4 years really have felt like 40, fml',
  },
  {
    id: genId(),
    isAuthor: true,
    name: 'Josph R. Biden',
    username: 'WillYouShutUpMan',
    bio:
      'I may sometimes forget who my wife is but at least I know who won the 2020 election :D',
  },
  {
    id: genId(),
    isAuthor: false,
    name: 'Vladimir Putin',
    username: 'UncleVladi',
    bio:
      'I am very proud of you Donnie, keep up the good work. Just remember to get back to mother russia before the left takes over your country lmao',
  },
  {
    id: genId(),
    isAuthor: false,
    name: 'Xavier Naidoo',
    username: 'aluhut33',
    bio: 'Dieses Land...ist keine Republik...Dieses Land...ist eine GmbH',
  },
]

const getUsers = () => users
const getAuthors = () => users.filter((u) => u.isAuthor)

const getUserById = (id: id): User | null => getEntityById(users, id)

export { User, getUsers, getAuthors, getUserById }
