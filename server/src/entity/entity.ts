type id = string
let currentId: number = 0

const genId = (): id => {
  currentId++
  return currentId.toString()
}

interface Entity {
  id: id
}

const getEntityById = <T extends Entity>(entities: T[], id: id): T | null =>
  entities.find((e) => e.id === id)

export { Entity, id, genId, getEntityById }
