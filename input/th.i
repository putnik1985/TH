[Mesh]
 [rectange]
  type = GeneratedMeshGenerator
  xmin = 0.
  xmax = 3.
  ymin = 0.
  ymax = 1.
  nx = 300
  ny = 100
  dim = 2
 []
[]

[Variables]
  [T]
  []
[]

[Kernels]
 [conduction]
  type = HeatConduction 
  variable = T
 []

 [dT_dt]
  type = SpecificHeatConductionTimeDerivative
  specific_heat = 6000.
        density = 3000.
       variable = T
 []
[]

[Materials]
 [thermal]
  type = HeatConductionMaterial
  thermal_conductivity = 12.0
 []
[]

[ICs]
 [domain]
  type = BoundingBoxIC
  variable = T
  
  x1 = 0.8333
  x2 = 1.1666
  y1 = 0.3333
  y2 = 0.6666

   inside = 268.15
  outside = 278.15
 []
[]

[BCs]

  [./bottom] # arbitrary user-chosen name
    type = NeumannBC
    variable = T
    boundary = bottom # This must match a named boundary in the mesh file
    value = 0.
  [../]

  [./top] # arbitrary user-chosen name
    type = NeumannBC
    variable = T
    boundary = top # This must match a named boundary in the mesh file
    value = 0.
  [../]

  [./left] # arbitrary user-chosen name
    type = DirichletBC
    variable = T
    boundary = left
    value = 278.15
  [../]

  [./right] # arbitrary user-chosen name
    type = NeumannBC
    variable = T
    boundary = right
    value = 0.
  [../]
[]

[Executioner]
  type = Transient
  solve_type = 'PJFNK'

  start_time = 0.0
   num_steps = 50
          dt = 0.0001
[]

[Outputs]
  exodus = true
[]
